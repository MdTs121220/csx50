//---------------------------------
//Markus Dwiyanto Tobi Sogen
//CS50 for teachers
//Indonesia
//readability.js
//---------------------------------
const readlineSync = require('readline-sync');
const text = readlineSync.question('Text: ');

let countLetter = 0;
let countWord = 1;
let countSentence = 0;

const textLeng = text.length;

for (let i = 0; i < textLeng; i++) {
  if (text[i].match(/[a-z]/i)) {  //in JavaScript, we must use (/[a-z]/i) can be used instead of isalpha() to check if a character is an alphabet.
    countLetter++;
  }
}

for (let i = 0; i < textLeng; i++) {
  if (text[i] === ' ') {
    countWord++;
  }
}

for (let i = 0; i < textLeng; i++) {
  if (text[i] === '.' || text[i] === '?' || text[i] === '!') {
    countSentence++;
  }
}

const calcu = (0.0588 * (countLetter / countWord * 100)) - (0.296 * (countSentence / countWord * 100)) - 15.8;
const index = Math.round(calcu);

if (index < 1) {
  console.log('Before Grade 1');
} else if (index > 16) {
  console.log('Grade 16+');
} else {
  console.log(`Grade ${index}`);
}