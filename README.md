<p align="center">
  <img src="resources/icons/vibechad.svg" alt="vibechad logo" width="150"/>
</p>

<h1 align="center">VibeChad: The Only Audio Visualizer You'll Ever Need (Probably)</h1>

<p align="center">
  <a href="https://github.com/yourusername/vibechad/actions/workflows/ci.yml"><img src="https://img.shields.io/github/actions/workflow/status/yourusername/vibechad/ci.yml?branch=main&label=Build%20Status&style=for-the-badge&logo=github" alt="Build Status"></a>
  <a href="https://github.com/yourusername/vibechad/releases"><img src="https://img.shields.io/github/v/release/yourusername/vibechad?style=for-the-badge&label=Latest%20Release&logo=github" alt="Latest Release"></a>
  <img src="https://img.shields.io/badge/Arch%20Linux-You%20know%20it-1793D1?style=for-the-badge&logo=arch-linux&logoColor=white" alt="Arch Linux">
  <img src="https://img.shields.io/badge/C%2B%2B17-Modern%20C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="C++17">
</p>

<p align="center">
  <i>"Hello, World!" but with more bass drops and fewer segfaults than your average dev bootcamp project.</i>
</p>

---

## 🎵 What is VibeChad?

VibeChad is not just *another* audio visualizer; it's *the* audio visualizer. Crafted with the discerning Arch Linux user in mind (because, let's be real, you wouldn't be here otherwise), VibeChad leverages the legendary ProjectM engine to deliver jaw-dropping, chad-tier visual experiences synchronized with your audio.

Think of it as your digital rave buddy, but without the questionable life choices. Whether you're a streamer needing next-level aesthetics, a music enthusiast craving eye candy, or just someone who appreciates finely tuned software, VibeChad has your back.

### ✨ Key Features (Because we don't do "basic")

*   **ProjectM Integration:** Harness the full power of ProjectM for dynamic, psychedelic, and customizable visualizations. We didn't reinvent the wheel; we just put some sick rims on it.
*   **Intuitive Qt6 UI:** A user interface so clean, your grandma could probably use it. But she won't, because she's too busy enjoying her vinyl collection.
*   **Real-time Audio Analysis:** Analyzes your audio in real-time, feeding delicious data to ProjectM for visuals that actually react to your tunes, not just some pre-baked nonsense.
*   **Overlay Engine:** Integrate text overlays. Because sometimes, you just need to drop some wisdom or memes on your visual output.
*   **Built-in Video Recorder:** Capture your epic visual journeys directly within the app. Share your vibes with the less fortunate (i.e., non-Arch users).
*   **Configurable to the Max:** Tweak every knob, slide every slider. Because true Chads customize everything.

---

## 🛠️ Get That Vibe: Building from Source

You use Arch, BTW. So building from source is practically foreplay.

### Prerequisites (The non-negotiables)

Before you embark on this glorious journey, ensure you have these bad boys installed:

*   **CMake** (>= 3.20)
*   **Qt6** (Core, Gui, Widgets, Multimedia, OpenGLWidgets, Svg)
*   **spdlog**
*   **fmt**
*   **taglib**
*   **toml++**
*   **GLEW**
*   **GLM**
*   **FFmpeg** (libavcodec, libavformat, libavutil, libswscale, libswresample)
*   **ProjectM** (v4 preferred. If you don't have it, consider running `scripts/install_projectm_v4_local.sh` or building it yourself. We're not your mom; figure it out.)

On Arch Linux, you can probably snag most of these with pacman:
```bash
sudo pacman -S cmake qt6-base qt6-multimedia qt6-svg spdlog fmt taglib tomlplusplus glew glm ffmpeg
# For projectM, check AUR or build it. A script is provided for local build.
```

### The Sacred Ritual: Compilation

```bash
# Clone this repo (if you haven't already, peasant)
git clone https://github.com/yourusername/vibechad.git
cd vibechad

# Build the beast
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release # Or Debug, if you like living dangerously
make -j$(nproc)

# Install (because you're worth it)
sudo make install
```

If `make install` gives you the cold shoulder, just run it from the `build` directory:
```bash
./vibechad
```

### 📦 Arch User Repository (AUR)

For the truly enlightened, VibeChad might just land in the AUR eventually. Keep an eye out. Until then, compiling is character building.

---

## 🧠 Configuration (For the Control Freaks)

VibeChad uses `toml++` for its configuration. The default configuration can be found in `config/default.toml`. Feel free to tweak it to your heart's content. Just try not to break everything. We're not responsible for your existential dread when your custom config vanishes into the ether.

---

## 🤝 Contributing (Show Us Your Code, Chad)

Think you can make VibeChad even more Chad-tier? Prove it. We welcome contributions, but only if they're up to snuff. No junior-dev-level pull requests, please. Read our `CONTRIBUTING.md` (once I write it, give me a minute) for the lowdown.

---

## 📜 License

This project is licensed under the MIT License. See the `LICENSE` file for details.
(Yes, I will add a `LICENSE` file. Don't rush me.)

---

## 🚀 The Future (Because we're always elevating)

We've got big plans, bigger vibes. Expect more features, more optimizations, and probably more "I use Arch, BTW" jokes. Stay tuned, stay Chad.

```
                  _                                         _   
                 | |                                       | |  
__   _____      _| |__   __ _ _ __   __ _  ___ ___    __ _| |_ 
\ \ / / _ \ \ /\ / / __| / _` | '_ \ / _` |/ __/ _ \  / _` | __|
 \ V /  __/\ V  V /| |_ | (_| | | | | (_| | (_|  __/ | (_| | |_ 
  \_/ \___| \_/\_/  \__| \__,_|_| |_|\__, |\___\___|  \__,_|\__|
                                      __/ |                     
                                     |___/                      
```