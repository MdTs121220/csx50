const readlineSync = require('readline-sync');

const height = Number(readlineSync.question('Height: '));

while (height < 1 || height > 8) {
  height = Number(readlineSync.question('Height: '));
}

for (let row = 0; row < height; row++) {
  for (let column = row + 1; column < height; column++) {
    console.log(' '); // print without newline
  }

  for (let hashes = height + row + 1; hashes > height; hashes--) { // right
    console.log('#');
  }

  console.log('  ');

  for (let hashes = height + row + 1; hashes > height; hashes--) { // left
    console.log('#');
  }

  console.log(); // add newline at the end of each row
}
