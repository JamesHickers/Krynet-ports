#import "SceneDelegate.h"

#import "KrynetApp.hpp"

@interface SceneDelegate ()
{
    KrynetApp* krynet;
}

@end

@implementation SceneDelegate

- (void)scene:
    (UIScene *)scene
    willConnectToSession:
    (UISceneSession *)session
    options:
    (UISceneConnectionOptions *)connectionOptions
{
    if (![scene isKindOfClass:[UIWindowScene class]])
        return;

    UIWindowScene* windowScene =
        (UIWindowScene*)scene;

    self.window =
        [[UIWindow alloc]
            initWithWindowScene:windowScene];

    krynet = new KrynetApp();

    if (!krynet->initialize())
    {
        [self showInitializationError];
        return;
    }

    UIViewController* controller =
        [[UIViewController alloc] init];

    self.window.rootViewController =
        controller;

    [self.window makeKeyAndVisible];
}

- (void)showInitializationError
{
    UIViewController* controller =
        [[UIViewController alloc] init];

    controller.view.backgroundColor =
        UIColor.systemBackground;

    UILabel* label =
        [[UILabel alloc] init];

    label.text =
        @"Krynet could not initialize.";

    label.textAlignment =
        NSTextAlignmentCenter;

    label.numberOfLines = 0;

    label.translatesAutoresizingMaskIntoConstraints =
        NO;

    [controller.view addSubview:label];

    [NSLayoutConstraint activateConstraints:@[
        [label.centerXAnchor
            constraintEqualToAnchor:
                controller.view.centerXAnchor],

        [label.centerYAnchor
            constraintEqualToAnchor:
                controller.view.centerYAnchor],

        [label.leadingAnchor
            constraintEqualToAnchor:
                controller.view.leadingAnchor
                constant:24],

        [label.trailingAnchor
            constraintEqualToAnchor:
                controller.view.trailingAnchor
                constant:-24]
    ]];

    self.window.rootViewController =
        controller;

    [self.window makeKeyAndVisible];
}

- (void)sceneDidDisconnect:(UIScene *)scene
{
    if (!krynet)
        return;

    krynet->shutdown();

    delete krynet;
    krynet = nullptr;
}

@end
