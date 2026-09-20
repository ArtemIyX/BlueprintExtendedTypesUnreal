# Blueprint Extended Types

Adds Blueprint-safe wrappers for native integer types Unreal does not expose as first-class Blueprint pins.

<img width="1275" height="785" alt="Some functions" src="https://github.com/user-attachments/assets/329365f6-2140-4fe5-acd2-c9943d0e3a5e" />


## Types

| Blueprint type | Native type | Range |
| --- | --- | --- |
| Int8 | `int8` | -128 to 127 |
| Int16 | `int16` | -32,768 to 32,767 |
| UInt16 | `uint16` | 0 to 65,535 |
| UInt32 | `uint32` | 0 to 4,294,967,295 |
| UInt64 | `uint64` | 0 to 18,446,744,073,709,551,615 |

<img width="162" height="126" alt="types" src="https://github.com/user-attachments/assets/d2dc344d-4c9c-4ed2-a708-d5c859edcf1d" />


## Install

1. Copy `BlueprintExtendedTypes` to your project's `Plugins` directory.
2. Regenerate project files if using C++.
3. Enable **Blueprint Extended Types** under **Edit > Plugins** and restart the editor.

## Blueprint

Nodes are in the **Blueprint Extended Types** category.

- `Try Make <Type>` validates an integer input and returns `false` when it is out of range. The output is reset to zero on failure.
- `Try Parse <Type>` parses decimal text with the same failure behavior.
- `Break <Type>` returns the value in the closest safe Blueprint representation.
- Comparison, `Min`, `Max`, and `Clamp` nodes work directly on the wrapper types.
- Safe widening conversions are autocasts. Narrowing conversions use `Try Convert` nodes.

`UInt64` is represented as a decimal `String` when breaking, formatting, or parsing, so its full range is preserved.

## C++

Add the module to your build dependencies:

```csharp
PublicDependencyModuleNames.AddRange(new[] { "BlueprintExtendedTypes" });
```

Use explicit construction and `GetValue()`:

```cpp
#include "BlueprintNativeTypes.h"

FBlueprintUInt32 id(42);
uint32 nativeId = id.GetValue();
```

The wrapped storage is intentionally private so unsupported native integer pins are not exposed to Blueprint.
