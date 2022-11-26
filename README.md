# Zqoi
free, Small and experimental lossless photographic image compression library with a C API and command-line interface with very high comprssion ratio.

It's compression ratio much better than PNG for photographic images and non photographic images.
The goal was to see if I could create a better lossless compressor than PNG in just several hours) using Zpaq and some past experience.  Zpaq is powerfull library.
I'm not expecting anyone else to use this, but feel free if you need some high compression ratio.
output of zqoi after decompressing is qoi format so if you want to look the result please install software that supports qoi format like irfanview 32 bit.

#### Example results

```
                 input       zqoi      comp_time    decomp_time   
$ dice.png      349,827      323,035      0.344s      0.328s
$ grass1.png    2,851,919   2,255,450     1.656s      1.766s
$ IMGP5482_seamless.png  2,649,220  1,489,005  1.203s  1.766s
```
qoir, qoi, libpng, wuffs, zpng and another run faster but compression ratio is behind zqoi.



#### How it works
first it compress png file using qoi after that compressed again using zpaq to get smaller files size.


### Excluded Libraries
zqoi need libzpaq.h to compress better

## License
Apache 2. See the [LICENSE](LICENSE) file for details.

#### Credits
Software by surya kandau
