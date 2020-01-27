# FNV-1a Non-Cryptographic Hashing Algorithm

This was created to provide a quick and easy hashing algorithm. I originally created it while writing a hash-table and wanted to use that algorithm in JS/TS.

[You can read more information here](https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function)

## Usage

Install from npm
`npm install fnv-hash`

Include in your code
```
import fnv1a from 'fnv-hash';

// or

const fnv1a = require('fnv-hash');

```

Pass in your plaintext to hash and the byte-size (32 or 64 right now). There are 3 functions:

Generic, pass the byte-size (defaults to 32)
```
fnv1a.fnv1a('hello', 64);
//=> 'a430d84680aabd0b'
```

Size: 32
```
fnv1a.fnv1a32('hello');
//=> '4f9f2cab'
```

Size: 64
```
fnv1a.fnv1a64('hello');
//=> 'a430d84680aabd0b'
```