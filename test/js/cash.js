//---------------------------------
//Markus Dwiyanto Tobi Sogen
//CS50 for teachers
//Indonesia
//cash.js
//---------------------------------
const readlineSync = require('readline-sync');

function getChangeOwed() {
  let changeOwed;

  do {
    changeOwed = readlineSync.question('Change owed: ');
  } while (changeOwed < 0);

  return Number(changeOwed) * 100; // convert to cents
}

function calculateQuarters(cents) {
  let quarters = 0;

  while (cents >= 25) {
    quarters++;
    cents -= 25;
  }

  return quarters;
}

function calculateDimes(cents) {
  let dimes = 0;

  while (cents >= 10) {
    dimes++;
    cents -= 10;
  }

  return dimes;
}

function calculateNickels(cents) {
  let nickels = 0;

  while (cents >= 5) {
    nickels++;
    cents -= 5;
  }

  return nickels;
}

function calculatePennies(cents) {
  let pennies = 0;

  while (cents >= 1) {
    pennies++;
    cents -= 1;
  }

  return pennies;
}

function main() {
  let cents = getChangeOwed();
  let quarters = calculateQuarters(cents);
  cents -= quarters * 25;
  let dimes = calculateDimes(cents);
  cents -= dimes * 10;
  let nickels = calculateNickels(cents);
  cents -= nickels * 5;
  let pennies = calculatePennies(cents);
  let coins = quarters + dimes + nickels + pennies;

  console.log(coins);
}

main();

