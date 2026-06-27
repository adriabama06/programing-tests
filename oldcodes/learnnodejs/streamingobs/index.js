const express = require('express');
const fs = require('fs');
const NodeMediaServer = require('node-media-server');

const config = {
  rtmp: {
    port: 1935,
    chunk_size: 60000,
    gop_cache: true,
    ping: 30,
    ping_timeout: 60
  },
  http: {
    port: 8000,
    allow_origin: '*'
  }
};
 
const nms = new NodeMediaServer(config)

const app = express();

app.get('/', async (req, res) => {
    res.send('ho');
});

nms.run();

app.listen(3000, async () => {
    console.log('ready');
});