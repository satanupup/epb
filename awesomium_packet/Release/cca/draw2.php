<?php

// 1.建立新影像
$im = imagecreate(500, 400);

// 2. 定義白色顏色的 RGB (背景顏色)
$white = imagecolorallocate($im, 255, 255, 255);

// 3. 定義使用者選擇的顏色
$rgb = split(",", $color);
$usercol = imagecolorallocate($im, $rgb[0], $rgb[1], $rgb[2]);

// 4. 開始畫線
imageline($im, $x1, $y1, $x2, $y2, $usercol);

// 5. 做成 png 圖檔並輸出
imagepng($im, "draw2.png");

// 6. 完成後將圖檔毀滅
imagedestroy($im);

?>
<html>
已輸出至 <a href="draw2.png">draw2.png</a>
</html>