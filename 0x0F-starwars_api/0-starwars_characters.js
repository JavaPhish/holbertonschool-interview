#!/usr/bin/node

const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];

request(url, async function (err, res, body) {
  if (err) throw err;
  const dataIds = JSON.parse(body).characters;

  for (const c of dataIds) {
    await new Promise((resolve) => {
      request(c, function (err, res, body) {
        if (err) {
          throw err;
        }
        console.log(JSON.parse(body).name);
        resolve();
      });
    });
  }
});
