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

Krynet Ports preserves platform access and maintains third-party client viability after Krynet's shift toward tighter control.

Official Windows support was discontinued with users redirected to WSL only. Independent clients are no longer welcome as before — this repo responds directly to that change.

## Official Upstream

- [Krynet-LLC GitHub](https://github.com/Krynet-LLC)
- [Krynet.ai](https://krynet.ai)

**Independent community project — not affiliated with Krynet LLC.**

## Mission

- Restore native Windows support (no WSL)
- Preserve discontinued platform builds
- Track Krynet web API compatibility
- Keep third-party clients viable
- Prevent forced environment lock-in

## What We Provide

- ✅ Native Windows executables
- ✅ Linux builds
- ✅ Android packages
- ✅ iOS Xcode source
- ✅ Active maintenance & API tracking

**No backend modifications — just maintained client wrappers.**

## Quick Install

### Windows/Linux/Android
1. [Releases page](https://github.com/JamesHickers/Krynet-ports/releases)
2. Download your platform binary
3. Run/install (no WSL needed on Windows)

### iOS
1. Grab iOS source from Releases
2. Open in Xcode
3. Sign & deploy

## Client Architecture

Krynet clients are **web wrappers** embedding `https://krynet.ai`:

- Native runtime (Sciter.JS/Lite, Ultralight, Electron, Tauri)
- Provides native window/OS integration
- Server handles core logic + cryptography

**Rendering engines are UI-only** — protocol compatibility depends on networking stack.

### Core Networking Requirements

| Component | Protocol | Purpose |
|-----------|----------|---------|
| **Gateway** | WebSocket (`wss://gateway.krynet.ai`) | Real-time messages, presence, events |
| **APIs** | REST/HTTPS (`/api/v1/user`, `/channels`, etc.) | Auth, accounts, history |
| **Files** | WebTransfer | Attachments, media |
| **Screenshare** | WebTransport + WebSocket (HTTP/3) | High-throughput streams (no WebRTC) |
| **Encryption** | TLS (HTTPS/WSS/HTTP/3) | All traffic secured |

**Minimum: Implement these for compatibility. UI engine doesn't matter.**

## Security & Encryption

**Layered state-of-the-art protection:**

### Messaging
- **Signal Protocol** (E2EE + forward secrecy)
- **Krynet layer** → **Double E2EE** (servers can't read)

### Voice/Screenshare
- **AES-GCM + TLS** streams
- **WebTransport** (no WebRTC IP leaks)

### Privacy Features
- Anonymous accounts
- Passwordless + WebAuthn/TPM
- Built-in: KrySearch, uBlock, Quad9 DNS

## Krynet.ai vs Discord

| Feature | Krynet.ai | Discord |
|---------|-----------|---------|
| Messaging | **Double E2EE** | TLS only |
| Voice/Video | AES-GCM/TLS, no WebRTC | WebRTC (IP leak risk) |
| Resources | **Low CPU/RAM** (native) | High (Electron) |
| Privacy Tools | **Encrypted search + blockers** | None |
| Platforms | Linux/iOS/Android/Web/WSL | Full native |
| Anonymity | **Yes** | Phone/email required |

**Krynet wins on privacy/performance; Discord leads ecosystem scale.**

## Developer Notes

- Krynet APIs change frequently — monitor updates
- UI flexible (Sciter → any WebView works)
- Custom clients must track gateway/API shifts
- Historically tolerated, now increasingly restricted

## Project Principles

- Platform independence
- User accessibility first
- Open frontend transparency
- Reliable availability
- No lock-in

## License

**GPLv3** — use, modify, distribute, fork freely.

Core Krynet proprietary; this repo wraps official webapp/builds only.

## ⚠️ Disclaimer

- **Not endorsed by Krynet LLC**
- May violate ToS
- Security/privacy risks possible
- **Use at your own risk**

---

**Krynet.ai © 2030** — Swedish ultra-private messenger for gamers/privacy users.
