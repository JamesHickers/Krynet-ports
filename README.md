# Krynet Ports (Unofficial)

<p align="center">
  Community-maintained Krynet.ai ports — preserving platform access and third-party viability.
</p>

<p align="center">
  <img src="https://img.shields.io/badge/License-GPLv3-blue.svg" alt="GPLv3 License">
  <img src="https://img.shields.io/badge/Platform-Windows-blue">
  <img src="https://img.shields.io/badge/Platform-Linux-yellow">
  <img src="https://img.shields.io/badge/Platform-Android-brightgreen">
  <img src="https://img.shields.io/badge/Platform-iOS-lightgrey">
  <img src="https://img.shields.io/badge/Status-Active-success">
</p>

---

## Statement

Krynet Ports exists to preserve platform access and maintain third-party client viability.

Recent public statements and platform decisions from Krynet leadership indicate a clear shift toward tighter control over client distribution and reduced tolerance for unofficial builds.

Official Windows support was discontinued.  
Users were redirected to WSL as the only supported method.  
Messaging now favors exclusively official clients.

The direction is clear:

Independent clients are no longer welcome in the ecosystem the way they once were.

This repository exists in direct response to that shift.

---

## Upstream / Official Repository

Official Krynet source and organization:

- https://github.com/Krynet-LLC  
- https://krynet.ai  

This project is independent and not affiliated with Krynet LLC.

---

## Mission

- Restore and maintain native Windows support
- Preserve access where official builds are discontinued
- Maintain compatibility with current Krynet web APIs
- Keep third-party implementations viable where technically possible
- Ensure users are not locked into specific environments

Platform access should not disappear because of policy changes.

---

## What This Repository Provides

- ✅ Native Windows client (compiled, ready-to-run)
- ✅ Linux builds
- ✅ Android builds
- ✅ iOS source package
- ✅ No WSL dependency for Windows
- ✅ Ongoing maintenance and API compatibility tracking

This project does not modify Krynet’s backend or services.  
It provides alternative client implementations and maintained platform builds.

---

## Installation

### Windows / Linux / Android

1. Navigate to the Releases page:  
   https://github.com/JamesHickers/Krynet-ports/releases  
2. Download your platform build.  
3. Run the executable or install the package.

No WSL required for Windows.

---

### iOS

1. Download the iOS source package from Releases.
2. Open the project in Xcode.
3. Configure signing and provisioning.
4. Build and deploy to your device.

# Client Architecture & Technical Requirements

Krynet clients are not tied to a specific UI framework.  
However, they must support the networking stack used by Krynet infrastructure.

The rendering engine only affects the **UI layer**, not protocol compatibility.

---

# Rendering Engine

Historically, Krynet clients have used **Sciter** for their interface.

Typical implementations:

- Desktop clients → **Sciter.JS**
- Mobile clients → **Sciter.Lite**

Sciter renders interfaces using:


HTML
CSS
JavaScript


inside a native application environment.

Earlier development discussions reportedly explored **Ultralight** before the project standardized on Sciter.

Because Krynet’s development direction changes frequently, the UI engine may change again in future versions.

Developers building custom clients should **not assume Sciter will always be used internally**.

Custom clients may use any rendering framework capable of handling Krynet networking requirements.

Examples include:

- Sciter
- Ultralight
- Electron
- Tauri
- Native WebView frameworks

The UI framework does **not determine protocol compatibility**.

---

# Core Networking Stack

All Krynet clients must support the following technologies.

---

## Gateway Communication

Real-time platform communication occurs through **WebSocket** connections.

This gateway handles:

- real-time messages  
- presence updates  
- channel events  
- server updates  
- notifications  

Example gateway connection:


wss://gateway.krynet.ai


The WebSocket connection remains active during the entire session.

---

## Platform APIs

Standard operations use **REST APIs**.

These endpoints manage:

- authentication  
- account information  
- message history  
- channel metadata  
- server configuration  

All API traffic occurs over HTTPS.

Example endpoints may include:


GET /api/v1/user
GET /api/v1/channels
POST /api/v1/messages


---

## File Transfers

Krynet uses an internal transfer system commonly referred to as **WebTransfer**.

This handles larger payloads such as:

- attachments  
- media uploads  
- file downloads  
- asset delivery  

These transfers occur outside the real-time gateway.

---

## Screen Sharing

Screen sharing uses a combination of:

- **WebTransport**
- **WebSocket**

WebTransport handles **high-throughput streaming of screen data**, while WebSocket manages **session control and signaling**.

This architecture avoids reliance on WebRTC.

Typical transport protocols include:


HTTP/3 (WebTransport)
WSS (WebSocket signaling)


---

## Encryption

All communications are secured using **TLS (Transport Layer Security)**.

Protocols used include:


HTTPS
WSS
HTTP/3


TLS ensures encrypted communication between clients and Krynet infrastructure.

---

# Minimum Client Requirements

A functional Krynet client must implement support for:


WebSocket → real-time gateway events
REST APIs → platform interaction
WebTransfer → file and media delivery
WebTransport → screen sharing streams
TLS → encrypted communication


The rendering engine used by the client **does not affect compatibility** as long as these networking requirements are correctly implemented.

---

# Developer Notes

Krynet’s internal architecture may change frequently.

Developers building custom clients should expect:

- API changes
- protocol adjustments
- gateway behavior updates
- potential client restrictions

Custom clients must adapt to these changes in order to remain compatible with the platform.

---

# Disclaimer

Custom clients may violate Krynet Terms of Service.

Historically, third-party clients existed in a gray area within the ecosystem, but recent platform direction suggests increasing restrictions on unofficial implementations.

Use at your own risk.

---

## Ecosystem Position

Historically, third-party clients operated in a gray area within the Krynet ecosystem.

Recent public positioning and platform changes indicate that this tolerance is ending.

This project represents a firm stance:

- Third-party development should not be erased.
- Platform choice should not be removed.
- Users should not be forced into indirect environments.
- Community ports should remain viable where technically possible.

If official support becomes restrictive or withdrawn, community support continues.

---

## Project Principles

- Platform independence
- User-first accessibility
- Open-source transparency
- Predictable availability
- No forced environment lock-in

---

## License

This project is licensed under the **GNU General Public License v3.0 (GPL-3.0)**.

You are free to:

- Use  
- Modify  
- Distribute  
- Fork  

All derivative works must comply with GPL-3.0.

See the `LICENSE` file for full terms.

# Krynet Ports (Unofficial)

<p align="center">
  Community-maintained Krynet.ai ports — preserving platform access and third-party viability.
</p>

<p align="center">
  <img src="https://img.shields.io/badge/License-GPLv3-blue.svg" alt="GPLv3 License">
  <img src="https://img.shields.io/badge/Platform-Windows-blue">
  <img src="https://img.shields.io/badge/Platform-Linux-yellow">
  <img src="https://img.shields.io/badge/Platform-Android-brightgreen">
  <img src="https://img.shields.io/badge/Platform-iOS-lightgrey">
  <img src="https://img.shields.io/badge/Status-Active-success">
</p>

---

## Statement

Krynet Ports exists to preserve platform access and maintain third-party client viability.

Recent platform decisions indicate a shift toward tighter control over client distribution and reduced tolerance for unofficial builds. Official Windows support was discontinued, redirecting users to WSL as the only supported method.

This repository exists in direct response: independent clients and alternative builds **should remain viable where technically possible**.

---

## Mission

- Restore and maintain native Windows support  
- Preserve access where official builds are discontinued  
- Maintain compatibility with current Krynet web APIs  
- Keep third-party implementations viable  
- Ensure users are not locked into specific environments  

---

## What This Repository Provides

- ✅ Native Windows client (compiled, ready-to-run)  
- ✅ Linux builds  
- ✅ Android builds  
- ✅ iOS source package  
- ✅ No WSL dependency for Windows  
- ✅ Ongoing maintenance and API compatibility tracking  

> This project **does not modify Krynet’s backend** — it provides alternative client implementations and maintained platform builds.

---

## Krynet Client Architecture

All Krynet clients — official and community — are **web wrappers around `https://krynet.ai`**.  

- Embed the web interface in a **native runtime** (Sciter, Ultralight, Electron, Tauri, etc.)  
- Provide a **native window, UI integration, and OS-specific features**  
- Core logic and cryptography remain **server-side at Krynet.ai**  

### Implications

- Messages remain **double E2EE (Signal + Krynet protocol)**  
- Voice/screenshare streams use **AES-GCM + TLS**, avoiding WebRTC leaks  
- Community ports are flexible but **not officially endorsed**; risks include malware, account flags, or privacy misconfigurations  

---

## Encryption & Security

Krynet uses **layered, state-of-the-art encryption**:

### 1️⃣ Messaging (Double Encryption)
- **Signal Protocol:** standard E2EE with forward secrecy  
- **Krynet Custom Protocol:** adds an additional cryptographic layer  
- ✅ Result: **double E2EE** — even servers cannot decrypt messages

### 2️⃣ Voice & Screenshare
- Real-time streams encrypted via **AES-GCM + TLS**  
- Uses **WebTransport + WebSocket**  
- No WebRTC → no IP leaks  

### 3️⃣ Privacy Advantages
- Anonymous accounts for discretion  
- Passwordless login + WebAuthn / hardware MFA  
- TPM support for device-level security  
- Encrypted search and privacy tools integrated (KrySearch, Adnauseam, uBlock, TrackMeNot, Quad9 DNS)

---

## Performance & Resource Efficiency

- Native wrappers (Sciter, Ultralight) **use minimal CPU, RAM, and GPU**  
- Efficient media streaming allows **gaming alongside Krynet** without FPS drops  
- Community ports can optimize overlays, FPS, and system usage beyond official apps  

> Compared to Electron apps like Discord, Slack, or Teams, Krynet is **far lighter and more efficient**.

---

## Developer & Community Focus

- **Target audience:** gamers, privacy lovers, security-conscious users, and those who value anonymity  
- **Developer tools:** plugins, mods, bots, and enterprise API integration for games/apps (UE5+, CryEngine)  
- Community ports allow **custom wrappers**, but come with **account and security risks**  

> Krynet is built by **game developers, software engineers, and privacy-focused enthusiasts**, not just social media engineers.

---

## UX & Inspiration

- Krynet borrows **UX ideas from Discord, Telegram, and Signal**  
- Implements these features with **unique architecture, lightweight performance, and privacy-first design**  
- Not a clone — it’s a **hybrid, gamer-focused platform**  

---

## Krynet.ai vs Discord — Comparison

| Feature | Krynet.ai | Discord |
|---------|-----------|---------|
| Messaging | **Double E2EE** (Signal + Krynet) | TLS only, NO EE2E |
| Voice/Video | AES-GCM + TLS, no WebRTC | WebRTC, potential IP leaks |
| IP Privacy | ✅ No leaks | ⚠️ Possible via WebRTC |
| Resource Usage | Low CPU/RAM/GPU | High CPU/RAM/GPU (Electron) |
| Community / Modding | Plugins, bots, enterprise API | Rich bot ecosystem, SDKs |
| Platform Support | Linux, iOS, Android, Web, WSL | Windows, macOS, Linux, iOS, Android, Web |
| Client Type | Lightweight native wrappers, community ports | Electron / web apps |
| Privacy Tools | Encrypted search, ad & tracker blockers | None built-in |
| Account Anonymity | ✅ Yes | ❌ Phone/email usually required |

**Verdict:**  
- **Privacy & security:** Krynet.ai wins  
- **Performance:** Krynet.ai wins  
- **Developer & game integration:** Krynet.ai strong for enterprise/custom apps  
- **Community features & scale:** Discord wins  

> **Community ports** of Krynet often **outperform Discord clients** in resource efficiency, FPS, and privacy, despite Discord’s polished native apps.

---

## Client Installation

### Windows / Linux / Android
1. Visit the [Releases page](https://github.com/JamesHickers/Krynet-ports/releases)  
2. Download your platform build  
3. Run the executable or install the package  

### iOS
1. Download iOS source from Releases  
2. Open in Xcode, configure signing  
3. Build and deploy to your device  

> No WSL required for Windows.

---

## Project Principles

- Platform independence  
- User-first accessibility  
- Open-source transparency (frontend and safe plugins)  
- Predictable availability  
- No forced environment lock-in  

---

## License

**GNU General Public License v3.0 (GPL-3.0)**

- Use, modify, distribute, fork  
- All derivatives must comply with GPL-3.0  

> Core Krynet.ai app and server remain proprietary; this repo only wraps official web interface or provides alternative builds.

---

## Disclaimer

- Independent community project, not endorsed or maintained by Krynet LLC  
- Use at your own risk  
- Community ports may violate terms of service or carry **security/privacy risks**  

---

**Krynet.ai © 2030** — Swedish-based, ultra-private, lightweight, mixed-source instant messaging & VoIP platform. Built for gamers, privacy enthusiasts, and security-conscious users.

---

## Disclaimer

This repository is an independent community project and is not endorsed, sponsored, or maintained by Krynet LLC.

Use at your own risk.
