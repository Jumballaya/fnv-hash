const test = require('ava');
const fnv1a = require('.');


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
        t.is(fnv1a(tt.text, 32), tt.expected[32]);
    });
});

test('32-bits is the default', t => {
    tests.forEach(tt => {
        t.is(fnv1a(tt.text, 123), tt.expected[32]);
    });
});

test('test 64-bit hash', t => {
    tests.forEach(tt => {
        t.is(fnv1a(tt.text, 64), tt.expected[64]);
    });
});