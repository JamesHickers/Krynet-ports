#import <Cocoa/Cocoa.h>

#include "KrynetApp.hpp"
#include "SciterView.hpp"

@interface KrynetWindowDelegate : NSObject
    <NSWindowDelegate>
{
    KrynetApp* krynet;
}

- (instancetype)initWithKrynet:
    (KrynetApp*)application;

@end

@implementation KrynetWindowDelegate

- (instancetype)initWithKrynet:
    (KrynetApp*)application
{
    self = [super init];

    if (self)
        krynet = application;

    return self;
}

- (BOOL)windowShouldClose:
    (NSWindow*)window
{
    if (krynet)
        krynet->shutdown();

    return YES;
}

@end

int main(
    int argc,
    const char* argv[]
)
{
    @autoreleasepool
    {
        NSApplication* application =
            [NSApplication sharedApplication];

        [application setActivationPolicy:
            NSApplicationActivationPolicyRegular];

        KrynetApp krynet;

        if (!krynet.initialize())
            return 1;

        NSRect frame =
            NSMakeRect(
                0,
                0,
                1280,
                800
            );

        NSWindow* window =
            [[NSWindow alloc]
                initWithContentRect:frame
                styleMask:
                    NSWindowStyleMaskTitled |
                    NSWindowStyleMaskClosable |
                    NSWindowStyleMaskMiniaturizable |
                    NSWindowStyleMaskResizable
                backing:NSBackingStoreBuffered
                defer:NO];

        [window setTitle:@"Krynet"];

        [window center];

        /*
         * Attach the Sciter native view here once
         * the exact Sciter macOS API is wired in.
         */

        KrynetWindowDelegate* delegate =
            [[KrynetWindowDelegate alloc]
                initWithKrynet:&krynet];

        [window setDelegate:delegate];

        [window makeKeyAndOrderFront:nil];

        [application activateIgnoringOtherApps:YES];

        [application run];

        [window close];

        return 0;
    }
}
