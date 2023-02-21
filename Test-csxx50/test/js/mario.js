//---------------------------------
//Markus Dwiyanto Tobi Sogen
//CS50 for teachers
//Indonesia
//mario-more.js
//---------------------------------

const readlineSync = require('readline-sync');

const height = Number(readlineSync.question('Height: '));

while (height < 1 || height > 8) {
  height = Number(readlineSync.question('Height: '));
}

for (let row = 0; row < height; row++) {
    for (let column = row + 1; column < height; column++) {
      process.stdout.write(' ');
    }
    for (let hashes = height + row + 1; hashes > height; hashes--) { // right
      process.stdout.write('#');
    }
    process.stdout.write('  ');
    for (let hashes = height + row + 1; hashes > height; hashes--) { // left
      process.stdout.write('#');
    }
    console.log(); // add newline at the end of each row
  }

  /*I use calls to process.stdout.write without a newline character can result in
  a single long line of output. This is why the output may not look like a pyramid.
  and adding console.log() at the end of each row, we ensure that each row is printed
  on a new line, and the output will be a pyramid
  */