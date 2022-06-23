const { interpolate } = require('./interpolation.js');

console.log(interpolate(0, 4, 3)); // [ 1, 2, 3 ]

console.log(interpolate(0, 1, 1)); // [ 0.5 ]

console.log(interpolate(0, 100, 4)); // [ 20, 40, 60, 80 ]