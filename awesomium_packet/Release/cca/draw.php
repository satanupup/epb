<?php

// 1.建立新影像
$im = imagecreate(500, 400);

// 2. 定義白色顏色的 RGB (背景顏色)
$white = imagecolorallocate($im, 255, 255, 255);

// 3. 定義黑色的 RGB (線的顏色)
$black = imagecolorallocate($im, 0, 0, 0);

// 4. 開始畫線
imageline($im, $x1, $y1, $x2, $y2, $black);

// 5. 做成 png 圖檔並輸出
imagejpeg($im, "draw.jpg");

// 6. 完成後將圖檔毀滅
imagedestroy($im);

?>
<html>
已輸出至 <a href="draw.jpg">draw.jpg</a>
</html>