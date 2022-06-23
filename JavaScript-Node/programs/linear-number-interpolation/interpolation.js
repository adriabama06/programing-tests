function interpolate(x, y, precission = 1) {
    precission = precission + 1;
    var toreturn = [];
    var smallnumber = x;
    var diference = y - x;

    if(x > y) {
        smallnumber = y;
        diference = x - y;
    }

    var diferenceByPrecission = diference / precission;

    for(var i = 1; i < precission; i++) {
        toreturn[i-1] = smallnumber + (diferenceByPrecission * i);
    }

    return toreturn;
}

module.exports = {
    interpolate
};