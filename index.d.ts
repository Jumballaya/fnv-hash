declare const fnv1a: {
	/**
	[FNV-1a](https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function) non-cryptographic hash function.
	@returns The hash as a hex string
	@example
	```
		import fnv1a from 'fnv1a';
		
		console.log(fnv1a('hello));
		//=> a430d84680aabd0b
	```
	*/
	(string: string, size: number): string;

};

export = fnv1a;