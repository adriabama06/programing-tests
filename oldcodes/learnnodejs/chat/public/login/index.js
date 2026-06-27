async function creatUrl(text) {
    if(!text.length) return;
    //window.location.replace(`/chat?usr=${text}`);
    window.location.href = `/chat?usr=${text}`;
}
/*async function creatUrl(text) {
    if(!text.length) return;
    var newurl = window.location.protocol + "//" + window.location.host + window.location.pathname +  `?usr=${text}`;
    window.history.pushState({path:newurl},'',newurl);
}

async function state() {
    console.log(window.location.href)
}*/