let clients = [];

exports.subscribe = function(req, res) {
    console.log('subscribe');
    clients.push(res);

    req.on('close', () => {
        clients.splice(clients.indexOf(res), 1);
    })
};

exports.publish = function(message) {
    console.log(`publish ${message}`);

    clients.forEach((res) => {
        res.setHeader('Access-Control-Allow-Origin', '*');
        res.end(message);
    });

    clients = [];
}