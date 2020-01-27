import {expectType} from 'tsd';
import fnv1a = require('.');

expectType<string>(fnv1a.fnv1a('hello world', 64));
expectType<string>(fnv1a.fnv1a32('hello world'));
expectType<string>(fnv1a.fnv1a64('hello world'));