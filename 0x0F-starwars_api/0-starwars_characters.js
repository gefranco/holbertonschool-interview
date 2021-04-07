#!/usr/bin/node

const request = require('request');
const film = process.argv[2];
request('https://swapi-api.hbtn.io/api/films/' + film + '/', async function (error, response, body) {
  if (response && response.statusCode !== 200) {
    return;
  }
  if (error) {
    return;
  }
  const json = JSON.parse(body);

  const characters = json.characters;

  for (let i = 0; i < characters.length; i++) {
    const response = await new Promise(function (resolve, reject) {
      request(characters[i], function (error, resonse, body) {
        if (error) {
          return;
        }
        const jsonCharacter = JSON.parse(body);
        resolve(jsonCharacter.name);
      });
    });
    console.log(response);
  }
});
