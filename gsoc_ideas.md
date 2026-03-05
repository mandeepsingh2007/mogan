# MoganLab GSoC 2026: Custom Project Proposals & Architectural Vision

This document outlines five highly researched, custom project proposals for MoganLab (XmacsLabs) under the GSoC 2026 "Bring Your Own Idea" (BYOI) track. These proposals are designed to strictly align with MoganLab's "High School First" educational priority and its ongoing architectural transition toward the Goldfish Scheme and modern C++/Qt frameworks.

---

## 1. Advanced Markdown-to-TMU Bidirectional Sync (Mogan Mark Mode)

### Architectural Background & Problem Statement
Markdown has become the de-facto standard for initial drafting among developers and researchers. While Mogan Editor natively utilizes the highly optimized `.tmu` (structured text) format, the lack of a robust bidirectional Markdown sync creates friction. Current workarounds suffer from parsing failures and formatting loss, particularly when handling nested lists, tables, and LaTeX-style math snippets ($E=mc^2$). A true bidirectional sync mechanism is required to map the `.tmu` Abstract Syntax Tree (AST) to Markdown structural nodes seamlessly.

### Proposed Technical Implementation
* **AST Parsing & One-Way Sync:** Integrate a highly performant, C-based Markdown parsing library (such as `cmark-gfm` or `md4c`) into Mogan’s C++ build system. This parser will ingest raw Markdown, generate an AST, and recursively map each node (headings, code blocks, math environments) directly into Mogan's internal `.tmu` data structures.
* **Reverse Sync (TMU to Markdown):** Develop a custom C++ module to traverse Mogan's internal document tree and serialize the `.tmu` elements back into standard Markdown syntax without data loss.
* **UI Integration:** Implement a split-view workspace mode using the Qt `QSplitter` widget, featuring a plain-text Markdown editor on the left and Mogan’s WYSIWYG renderer on the right. Modify text signals with debounce logic to ensure smooth, real-time live previews without UI freezing.

---

## 2. Native Interactive Geometry & Algebraic Graphing Canvas

### Architectural Background & Problem Statement
To truly fulfill the "High School First" philosophy, Mogan STEM needs native, interactive visualization tools. Currently, drawing geometry diagrams or plotting functions relies on external binaries like Gnuplot or Eukleides. These third-party dependencies introduce cross-platform compatibility issues and lack the interactivity required for live classroom demonstrations (e.g., dragging points to dynamically alter an equation).

### Proposed Technical Implementation
* **Canvas Backend:** Build an in-house 2D vector graphics canvas leveraging the Qt Graphics View Framework (`QGraphicsScene` and `QGraphicsView`). Develop a custom C++ class hierarchy for geometric primitives (Points, Lines, Circles, Polygons).
* **Bidirectional Data Binding:** Deeply integrate the C++ shape objects with Mogan’s underlying Scheme macro system. When a user interacts with the canvas (e.g., drags a circle's radius), the Qt event loop will capture the transformation and instantly update the corresponding mathematical coordinates and `.tmu` document code.
* **Algebraic Graphing:** Integrate a lightweight module (potentially utilizing `QCustomPlot`) to parse and plot algebraic functions on a real-time coordinate system natively within the editor.

---

## 3. Comprehensive SRFI Implementations for Goldfish Scheme Engine

### Architectural Background & Problem Statement
MoganLab's transition from S7 Scheme to its proprietary, R7RS-small compliant "Goldfish Scheme" is a critical architectural shift. To fully support complex plugins (like document tree parsing and matrix operations) and safely deprecate legacy Python extensions, the Goldfish Scheme requires a robust standard library of SRFIs (Scheme Requests for Implementation). 

### Proposed Technical Implementation
Implement missing, high-priority SRFIs directly bridging the C engine and Scheme wrapper layers:
* **SRFI-1 (List Library):** Implement mandatory procedures, utilizing C-level macros to optimize heavily recursive and time-consuming operations.
* **SRFI-69 / SRFI-125 (Basic Hash Tables):** Develop the backend purely in C to ensure maximum performance. This involves designing a generic hash function, managing secure memory allocation (malloc/free), handling collision resolution (chaining/open addressing), and exposing the bindings to the interpreter.
* **SRFI-133 (Vector Library):** Model vectors as fixed-size continuous memory blocks in C to achieve $O(1)$ time complexity for data access. Rigorous testing using Valgrind will be enforced to prevent memory leaks and dangling pointers during garbage collection.

---

## 4. On-Device AI "Math-to-Text" Explainer & Contextual Formula Generator

### Architectural Background & Problem Statement
Generative AI is a powerful tool for accelerating academic writing. Mogan’s `.tmu` format has lower information entropy than LaTeX, making it exceptionally token-efficient for LLMs. High school students often experience high cognitive load when trying to write or decode complex mathematical macros. Integrating a privacy-first, Agentic AI workflow directly into the editor can drastically reduce this barrier to entry.

### Proposed Technical Implementation
* **Architecture Setup:** Build a Scheme-based plugin and a C++ network layer capable of asynchronous API requests. The system will default to local LLM endpoints (via Ollama or `llama.cpp`) to ensure data privacy, with fallback support for cloud APIs.
* **Natural Language to Equation Engine:** Implement a text input module where users can type requirements in plain English. The context will be wrapped in a highly optimized system prompt instructing the LLM to output exclusively in `.tmu` macro structure, which is then parsed and rendered instantly in the WYSIWYG canvas.
* **Interactive Contextual Explainer:** Develop a Qt-based dockable sidebar. When a user highlights a complex equation, the C++ backend will serialize the equation's AST into text and pass it to the LLM. The AI will generate a formatted mathematical breakdown, variable definitions, and contextual logic directly in the sidebar.

---

## 5. Native Git Version Control Integration & TMU Structural Diff Viewer

### Architectural Background & Problem Statement
Collaboration is fundamental to modern research. However, standard Git calculates plain-text, line-by-line differences. Because Mogan’s `.tmu` format is an XML-like hierarchical tree, a minor semantic change (like moving a list item) results in massive, unreadable raw-code diffs. To make Mogan viable for collaborative university environments, it requires a visual, structural diff viewer rendered directly on the canvas.

### Proposed Technical Implementation
* **Git Backend Embedding:** Integrate `libgit2` (the standard C implementation of Git) into the Qt C++ framework, eliminating dependency on command-line utilities. Build a visual branch manager and commit history viewer using Qt's model/view architecture.
* **Structural Diffing Algorithm:** Implement an advanced Tree Edit Distance algorithm (e.g., Zhang-Shasha). Instead of line-by-line comparisons, the algorithm will load two `.tmu` ASTs into memory and compare them node-by-node to identify exact insertions, deletions, and updates.
* **Visual Renderer Integration:** Map the diff algorithm's output to Mogan's visual renderer. Modified formulas and text environments will display track-changes styling directly on the canvas (e.g., old nodes highlighted with a red background and strikethrough, new nodes with a green background).
