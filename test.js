const test = require('ava');
const { fnv1a, fnv1a32, fnv1a64 } = require('.');


const tests = [
    {
        text: 'hello',
        expected: {
            32: '4f9f2cab',
            64: 'a430d84680aabd0b',
        },
    },
    {
        text: '12345',
        expected: {
            32: '43c2c0d8',
            64: 'e575e8883c0f89f8',
        },
    },
    {
        text: 'it was the best of times, it was the worst of times.',
        expected: {
            32: 'e65b1fd4',
            64: 'c3e36f39d0565e54',
        },
    }
]

test('test 32-bit hash', t => {
    tests.forEach(tt => {
        t.is(fnv1a32(tt.text), tt.expected[32]);
    });
});

test('test 64-bit hash', t => {
    tests.forEach(tt => {
        t.is(fnv1a64(tt.text), tt.expected[64]);
    });
});

test('test generic fnv1a function', t => {
    tests.forEach(tt => {
        const bit = ([32, 64, 123])[Math.floor(Math.random() * 3)];
        t.is(fnv1a(tt.text, bit), tt.expected[bit === 123 ? 32 : bit]);
    });
});