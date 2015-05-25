document.getElementById("addButton").addEventListener(("click"), lottoNum);

var lottoNum = new Array(7);
var i;
for(i=0; i<lottoNum.length; i++){
  var rNum = Math.floor(Math.random()*100%45+1);
  var j = 0;
  while(j < i){
    if(rNum == lottoNum[j]){
      rNum = Math.floor(Math.random()*100%45+1);
      j = 0;
      continue;
    }
    j++;
  }
  lottoNum[i] = rNum;
}

/*forEach 찾아보고 바꾸기*/
/*for(item in numArr)*/

var numOfClick=0;
function lottoNum(){
  numOfClick++;
  if(numOfClick <= lottoNum.length){
    var numList = document.getElementById('numList');
    var numBox = document.createElement('li');
    numList.appendChild(numBox);
    numBox.textContent = lottoNum[numOfClick-1];
  }
  else{
    addButton.disabled = true;
  }
}
/*removeEventListener */

/*function lottoNum(){
  numOfClick++;
  if(numOfClick == 1)
    document.getElementById("num1").innerHTML = lottoNum[0];
  else if(numOfClick == 2)
    document.getElementById("num2").innerHTML = lottoNum[1];
  else if(numOfClick == 3)
    document.getElementById("num3").innerHTML = lottoNum[2];
  else if(numOfClick == 4)
    document.getElementById("num4").innerHTML = lottoNum[3];
  else if(numOfClick == 5)
    document.getElementById("num5").innerHTML = lottoNum[4];
  else if(numOfClick == 6)
    document.getElementById("num6").innerHTML = lottoNum[5];

}*/
