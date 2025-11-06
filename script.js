// Завдання №4

let userName = prompt("Як вас звати?");
let userAge = prompt("Скільки вам років?");
let userCity = prompt("З якого ви міста?");
let userColor = prompt("Ваш улюблений колір?");

let message = `Привіт, ${userName}! Тобі ${userAge} років, ти з міста ${userCity}, і твій улюблений колір — ${userColor}.`;

alert(message);
console.log(message);

// Завдання №5

let length = prompt("Введіть довжину прямокутника:");
let width = prompt("Введіть ширину прямокутника:");

length = Number(length);
width = Number(width);

let area = length * width;
let perimeter = 2 * (length + width);

console.log(`Площа прямокутника: ${area}`);
console.log(`Периметр прямокутника: ${perimeter}`);

alert(`Площа: ${area}, Периметр: ${perimeter}`);

// Перетворення см у метри
let cm = prompt("Введіть значення у сантиметрах:");
let meters = cm / 100;
alert(`${cm} см = ${meters} м`);

// Середнє значення двох чисел
let a = Number(prompt("Введіть перше число:"));
let b = Number(prompt("Введіть друге число:"));
let avg = (a + b) / 2;
alert(`Середнє значення: ${avg}`);

// Завдання №6

let choice = prompt("Що ви хочете конвертувати? (1 - метри в см, 2 - см у метри)");

if (choice == "1") {
  let meters = Number(prompt("Введіть метри:"));
  let cm = meters * 100;
  alert(`${meters} метрів = ${cm} сантиметрів`);
} else if (choice == "2") {
  let cm = Number(prompt("Введіть сантиметри:"));
  let meters = cm / 100;
  alert(`${cm} сантиметрів = ${meters} метрів`);
} else {
  alert("Некоректний вибір!");
}

// Завдання №7

let birthYear = prompt("Введіть ваш рік народження:");
let currentYear = new Date().getFullYear();
let age = currentYear - birthYear;

alert(`Вам ${age} років!`);
console.log(`Рік народження: ${birthYear}, Вік: ${age}`);