var randomNumber1 = Math.floor(Math.random() * 6) + 1; //1-6
var randomNumber2 = Math.floor(Math.random() * 6) + 1;

var randomDice1 = document
  .querySelector(".dice1 img")
  .setAttribute("src", "./images/dice" + randomNumber1 + ".png");

var randomDice2 = document
  .querySelector(".dice2 img")
  .setAttribute("src", "./images/dice" + randomNumber2 + ".png");

if (randomNumber1 > randomNumber2) {
  document.querySelector(".heading").textContent = "🚩 Player 1 Wins";
} else if (randomNumber2 > randomNumber1) {
  document.querySelector(".heading").textContent = "🚩 Player 2 Wins";
} else {
  document.querySelector(".heading").textContent = "Draw";
}
