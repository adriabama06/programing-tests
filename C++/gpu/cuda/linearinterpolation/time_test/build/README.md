# Pre-compiled for Windows x64 and Cuda 11.3

# PC:
- [I7 11700kf](https://www.intel.in/content/www/in/en/products/sku/212048/intel-core-i711700kf-processor-16m-cache-up-to-5-00-ghz/specifications.html)
- [RTX 3080](https://www.nvidia.com/es-es/geforce/graphics-cards/30-series/rtx-3080-3080ti/) \[[exactliy this](https://www.pccomponentes.com/msi-geforce-rtx-3080-ventus-3x-plus-oc-lhr-10gb-gddr6x?gclid=CjwKCAjwzeqVBhAoEiwAOrEmzWzoSc1vgd9BMQssqOtsW8Ys1Vjo6o1XrKe_-FgzU8Ulqn9rkDzK2xoConIQAvD_BwE)\]

# Times

- Cpu Single: `1.10` seconds
- Cpu Multi: `62.45` seconds (i believe this is slow because create new thread require some time and this is a basic calculation don't make get better time, using 4 threads windows crashes)
- Gpu Single Grid 1: `0.16` seconds
- Gpu Single Grid 8: `0.16` seconds (in this casi I believe this don't run fast because I don't optimize the code)