const test = require('ava');
const fnv1a = require('.');


const tests = [
    { text: 'hello', expected: 'a430d84680aabd0b' },
    { text: '12345', expected: 'e575e8883c0f89f8' },
    {
        text: 'it was the best of times, it was the worst of times.',
        expected: 'c3e36f39d0565e54',
    }
]

test('default', t => {
    tests.forEach(tt => {
        t.is(fnv1a(tt.text), tt.expected);
    });
});