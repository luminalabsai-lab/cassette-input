# Cassette Input

A JUCE 7 audio plugin (AU/VST3, macOS Universal & Windows x64) emulating the cassette INPUT path of a Portastudio, including preamp, tape compression, head-bump EQ, wow/flutter, noise, crosstalk, and more.

## Features

- Input trim (−18 dBFS = 0 VU)
- Preamp soft-knee asym sat + DC bias (ZDF)
- TapeComp (A=1–3 ms, R=50–200 ms, auto makeup)
- Head-bump EQ (80–120 Hz, level-sens Q, parallel blend)
- Bandwidth limiting (hi cut 6–12 kHz, low cut 20–80 Hz)
- Wow/Flutter (dual LFOs + jitter, transport-sync, delay-free pitch)
- Noise (hiss with autogate < −70 dBFS; 60 Hz hum + harmonics)
- Crosstalk 0–5%
- Mix/Output with Quality: Draft (1x), Normal (2x), High (4x)
- Parameter smoothing, denormal handling, lock-free audio path
- Skeuomorphic one-page UI (vector), cassette animation, VU meters
- 8 presets: Direct Cassette, Crunchy Input, Warped Walkman, Bedroom Jangle, Soft Knee Jazz, Indie Grit, Tape Chorusey, Clean With Hiss

## Install Paths

- **macOS (AU):** `~/Library/Audio/Plug-Ins/Components/CassetteInput.component`
- **macOS (VST3):** `~/Library/Audio/Plug-Ins/VST3/CassetteInput.vst3`
- **Windows (VST3):** `%PROGRAMFILES%\Common Files\VST3\CassetteInput.vst3`

## Optional Code Sign (macOS)

```sh
codesign --force --deep --sign "Developer ID Application: Your Name" --timestamp build/CassetteInput_artefacts/Release/AU/CassetteInput.component
codesign --force --deep --sign "Developer ID Application: Your Name" --timestamp build/CassetteInput_artefacts/Release/VST3/CassetteInput.vst3
```

## Building

### macOS (Universal)
```sh
brew install cmake
./scripts/build_mac.sh
```

### Windows (x64)
```powershell
.\scripts\build_win.ps1
```

## License

MIT for all original code. JUCE is under its own license (see JUCE submodule).

## See `validation.md` for plugin validation criteria.
