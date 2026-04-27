# 🚀 Chandrayaan Mission — Animated Story in C++

> **Semester 2 Project | Computer Graphics Subject**
> A scene-by-scene animated story of India's Chandrayaan Moon Mission, built entirely in C++ using `graphics.h`.

---

## 👨‍💻 About This Project

This is my **Subject-Specific Project for Semester 2**, made as part of my Computer Graphics coursework.

Instead of doing a typical static graphics program, I decided to explore a completely different side of C++ graphics — **storytelling through animation**. The idea was simple: what if I could tell the entire story of the Chandrayaan mission frame by frame, using nothing but basic `graphics.h` primitives?

No game engine. No external libraries. No fancy frameworks.
Just `circles`, `rectangles`, `lines`, `loops`, and a lot of `delay()`. 😄

It was a fun challenge to think like an animator — figuring out how to move objects pixel by pixel, simulate flames, make stars twinkle, and bring a lander softly down onto the Moon surface — all within the constraints of a single `.cpp` file.

---

## 🎬 Animation Scenes

The program plays through **5 scenes** automatically, one after another:

| # | Scene | What You See |
|---|-------|-------------|
| 1 | 🛸 **Launch Pad** | Rocket on the pad, 10-second countdown, smoke puffs at ignition |
| 2 | 🔥 **Rocket Launch** | Rocket lifts off with flames, clouds scroll down, sky turns from blue → black |
| 3 | 🌌 **Space Travel** | Starfield, Earth shrinking behind, Moon growing ahead, stars twinkling |
| 4 | 🌕 **Moon Landing** | Lander descends with thruster fire, dust particles, "TOUCHDOWN!" flash |
| 5 | 🇮🇳 **Mission Success** | Moon surface, Vikram lander, Indian flag, flashing success message |

---

## 🛠️ Tech Stack

| Thing | Detail |
|-------|--------|
| Language | C++ |
| Graphics Library | `graphics.h` (WinBGI / Turbo C++ style) |
| Animation method | Frame-by-frame with `cleardevice()` + `delay()` |
| File count | **1 file** — `main.cpp` |
| External dependencies | **None** |

---

## 📁 Project Structure

```
chandrayaan-animation/
│
├── main.cpp        ← entire project lives here
└── README.md
```

---

## ▶️ How to Run

### Option 1 — WinBGI on Windows *(Recommended)*

1. Download and install [WinBGI](https://winbgi.sourceforge.net/)
2. Compile with g++:

```bash
g++ main.cpp -o chandrayaan -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
```

3. Run:

```bash
./chandrayaan.exe
```

### Option 2 — Turbo C++ / DOSBox

1. Open `main.cpp` in Turbo C++
2. Make sure the BGI driver path is set correctly in `initgraph()`
3. Hit **Compile → Run**

---

## 🧠 What I Learned

- How to animate objects using frame loops (`for` + `cleardevice()` + `delay()`)
- Using `fillpoly()` to draw triangles for rocket nose cones and fins
- Simulating motion by incrementing/decrementing pixel coordinates
- Creating visual effects like flame flicker, star twinkle, and dust particles using `rand()`
- Structuring a graphics program scene-by-scene using functions
- The whole experience of thinking like an **animator**, not just a programmer

---

## ✨ What Makes This Different

Most C++ graphics projects draw a static scene — a house, a traffic light, a flag.

I wanted to push further and **tell a story**. Every scene flows into the next, objects actually *move*, and there's a beginning, middle, and end. It felt less like writing code and more like directing a short film — just with rectangles and circles instead of a camera.

---

## 🌖 Inspired By

India's real **Chandrayaan-3 Mission** (August 2023) — where ISRO successfully landed the Vikram lander near the Moon's south pole, making India the first country to achieve this. 🇮🇳

---

## 📌 Note

This project was made purely for learning purposes as part of my academic curriculum. It intentionally keeps things simple and beginner-friendly — no OOP, no multiple files, no advanced concepts. Just pure C++ graphics fundamentals.

---

*Made with curiosity, a lot of `delay()`s, and pride in ISRO 🚀*