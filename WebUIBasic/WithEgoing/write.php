<?php
	$conn=mysqli_connect('localhost:3306/','root',aldialdi7);
	mysqli_select_db($conn,'opentutorials');
	$result=mysqli_query($conn, "SELECT * FROM topic");
?>
<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<link rel="stylesheet" type="text/css" href="http://localhost:8080/style.css">
</head>
<body id="target">
	<header>
		<img src="http://www.bajeori.pe.kr/iconimg/images/back/b1.gif" alt="봄" />
		<h1><a href="http://localhost:8080/index.php">JavaScript</a></h1>
	</header>
	<nav>
		<ol>
			<?php
				while($row=mysqli_fetch_assoc($result)){
				echo '<li><a href="http://localhost:8080/index.php?id='.$row['id'].'">'.$row['title'].'</a></li>'."\n";
				}
			?>
		</ol>
	</nav>
	<div id="control">
		<input type="button" value="white" id="white_btn"/>
		<input type="button" value="black" id="black_btn"/>
		<a href="http://localhost:8080/write.php">write</a>
	</div>
	<script src="http://localhost:8080/script.js"></script>
	<article>
	<form action="process.php" method="post">
		<p>
			제목:<input type="text" name="title">
		</p>
		<p>
			작성자:<input type="text" name="author">
		</p>
		<p>
			본문:<textarea name="description"></textarea>
		</p>
		<input type="submit" name="name">

	</form>
	</article>
</body>
</html>
