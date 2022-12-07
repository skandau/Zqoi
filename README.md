# Zqoi
combining qoi with zpaq to get high compression ratio.

It's compression ratio much better than PNG, QOI, QOIR, Wuffs for photographic and non photographic images.
Now output of zqoi after decompressing is in PNG format, so just open it.
first put qoiconv.exe and zqoi.exe on drive D: and then run d:\zqoi.exe

#### Example results

```
zqoi v1          input       zqoi      comp_time    decomp_time   
$ dice.png      349,827      323,035      0.344s      0.328s
$ grass1.png    2,851,919   2,255,450     1.656s      1.766s
$ IMGP5482_seamless.png  2,649,220  1,489,005  1.203s  1.766s

zqoi v2           zqoi
$ dice.png       273,309  
$ grass1.png     2,112,158
$ IMGP5482_seamless.png   1,396,367
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
