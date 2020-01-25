import {expectType} from 'tsd';
import fnv1a = require('.');

expectType<string>(fnv1a('hello world'));
