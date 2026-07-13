# RTSyn Port

RTSyn Port is the C library for implementing the object ports.

## Public API

The public API is declared in:

- `include/rtsyn/port.h`: port used to send values through different RTSyn objects.
- `include/rtsyn/port/value.h`: abstraction of the different RTSyn values.

## Generating Documentation

Run:

```sh
xmake doxygen
```

Then open `build/html/index.html`.
