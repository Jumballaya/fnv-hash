declare const fnv1a: {
	/**
	[FNV-1a](https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function) non-cryptographic hash function.
	@returns The hash as a hex string
	@example
	```
		import { fnv1a } from 'fnv1a';
		
		console.log(fnv1a('hello', 64));
		//=> a430d84680aabd0b
	```
	*/
	fnv1a: (string: string, size: number) => string;

	/**
	[FNV-1a](https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function) non-cryptographic hash function.
	@returns The hash as a 32-bit hex string
	@example
	```
		import { fnv1a32 } from 'fnv1a';
		
		console.log(fnv1a32('hello'));
		//=> 4f9f2cab
	```
	*/
	fnv1a32: (string: string) => string;

	/**
	[FNV-1a](https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function) non-cryptographic hash function.
	@returns The hash as a 64-bit hex string
	@example
	```
		import { fnv1a64 } from 'fnv1a';
		
		console.log(fnv1a64('hello'));
		//=> a430d84680aabd0b
	```
	*/
	fnv1a64: (string: string) => string;
};

export = fnv1a;