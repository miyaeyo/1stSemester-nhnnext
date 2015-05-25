<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
</head>
<body>
  <h1>JS</h1>
  <ul>
  <script charset="utf-8">
    list = new Array("one", "two", "three");
    i = 0;
    while(i<list.length){
      document.write("<li>"+list[i]+"</li>");
      i++;
    }
  </script>
  </ul>

  <h2>php</h2>
  <ul>
    <?php
      $list = array("one", "two", "three");
      $i = 0;
      while($i<count($list)){
        echo "<li>".$list[$i]."</li>";
        $i++;
      }

    ?>
  </ul>

</body>
</html>
