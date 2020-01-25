const binary = require('node-pre-gyp');
const path = require('path');
const bindingPath = binary.find(path.resolve(__dirname, './package.json'));
const fnv1aModule = require(bindingPath);

module.exports = fnv1aModule.fnv1a;