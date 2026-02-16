# Binary Tree Project - How Files Link Together

## How C++ Compilation Works

### Step 1: Compilation (.cpp → .obj)
Each .cpp file is compiled **independently** into an object file (.obj):
- `BinaryTrees.cpp` → `BinaryTrees.obj`
- `BinaryTreeSearchInsert.cpp` → `BinaryTreeSearchInsert.obj`
- `Delete.cpp` → `Delete.obj`
- `Main.cpp` → `Main.obj`

### Step 2: Linking (.obj → .exe)
The linker combines all .obj files into one executable:
- Links function calls to their definitions
- Resolves all references between files
- Creates the final .exe

## Your Project Structure (Incremental Complexity)

### Version 1: BinaryTrees.h/cpp (BASIC)
**Features**: Simple tree creation, inorder traversal
**Use in Main.cpp**: `#include "BinaryTrees.h"`

### Version 2: BinaryTreeSearchInsert.h/cpp (INTERMEDIATE)
**Features**: Insert, Search, Inorder traversal
**Use in Main.cpp**: `#include "BinaryTreeSearchInsert.h"`

### Version 3: Delete.h/cpp (ADVANCED)
**Features**: Insert, Search, Delete, Inorder traversal
**Use in Main.cpp**: `#include "Delete.h"`

## How to Switch Between Versions

### In Main.cpp:
```cpp
// VERSION 1 - Basic
#include "BinaryTrees.h"

// VERSION 2 - With Insert/Search
// #include "BinaryTreeSearchInsert.h"

// VERSION 3 - With Delete
// #include "Delete.h"
```

### In Visual Studio Project:
**Right-click each .cpp file → Properties → Excluded From Build**
- To use Version 1: Exclude BinaryTreeSearchInsert.cpp and Delete.cpp
- To use Version 2: Exclude BinaryTrees.cpp and Delete.cpp
- To use Version 3: Exclude BinaryTrees.cpp and BinaryTreeSearchInsert.cpp

## Key Rules

1. **Header files (.h)**: Declarations only (what exists)
2. **Source files (.cpp)**: Definitions (how it works)
3. **#pragma once**: Prevents including the same header twice
4. **One definition rule**: Each class/struct can only be defined once across all files
5. **Main.cpp**: Only include ONE version's header at a time

## Current Status
✅ Fixed: Missing semicolon in Delete.h
✅ Fixed: Added missing function implementations
✅ Each version is now self-contained
