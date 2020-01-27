const binary = require('node-pre-gyp');
const path = require('path');
const bindingPath = binary.find(path.resolve(__dirname, './package.json'));
const fnv1aModule = require(bindingPath);

const SIZES = [32, 64];

function fnv1a(plain, size) {
    if (!SIZES.some(s => s === size)) size = 32;
    return fnv1aModule.fnv1a(plain, size);
}

function fnv1a32(plain) {
    return fnv1aModule.fnv1a32(plain);
}

function fnv1a64(plain) {
    return fnv1aModule.fnv1a64(plain);
}

module.exports = {
    fnv1a,
    fnv1a32,
    fnv1a64,
};