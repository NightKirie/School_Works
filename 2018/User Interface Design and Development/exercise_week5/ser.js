// include `express`
// 載入 `express`
const express = require('express')

// create an express, aka web server, instance
// 建立一個 express (也就是網頁伺服器)實體
const app = express()
const port = 13579

// handle other urls
// 處理其它網址
app.use(express.static(`${__dirname}/dist`))

app.get('/search', (req, res) => {
  res.send(`<h1>Hello, ${req.query.name} </h1>`)
})

app.get('/add', (req, res) => {
  let fs = require('fs');
  fs.writeFile('dist/students.json', JSON.stringify(req.query), function (err,) {
    if (err)
        console.log(err);
    else
        console.log('Write operation complete.');

  });
  res.send("add successed");
})

app.get('/delete', (req, res) => {
  let fs = require('fs');
  let path = 'dist/students.json';
  fs.writeFile('dist/students.json', JSON.stringify(req.query), function (err) {
    if (err)
        console.log(err);
    else
        console.log('Write operation complete.');
  });
  res.send("delete successed");

})



// start the server
// 啟動伺服器
app.listen(port, () => {
  console.log(`listening on port: ${port}`)
})




