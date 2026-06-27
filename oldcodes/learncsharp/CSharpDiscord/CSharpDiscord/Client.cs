using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using CSharpDiscord.src;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;

namespace CSharpDiscord {
    class Client {
        static async Task<int> Main(string[] args) {
            Console.WriteLine("Hello World!");
            Request.setToken("NzkzOTM3MzAyMjE2MjQ1MjY4.X-zhuw.UT2dSkBMe5UO_Zo3yJiAzoHv00g");
            //var res = await Request.Get("/channels/872831681986437150/messages?limit=1");
            //var json = JsonConvert.DeserializeObject<List<dynamic>>(res);
            //var json = await Request.Get("/users/@me");
            //dynamic f = JObject.Parse(json.ToArray()[0].ToString());
            //Console.WriteLine(json.GetValue("username"));
            //Request.Custom("/channels/793937971635290121/messages", "POST", " \"content\": \"hola desde c#\"");

            //var jsonArray = await Request.ArrayGet("/channels/872831681986437150/messages?limit=5");
            //
            //for(int i = 0; i < jsonArray.Count; i++)
            //{
            //    Console.WriteLine(jsonArray[i].GetValue("content"));
            //}

            //var jsonPost = await Request.Post("https://httpbin.org/post", "{\"conent\": \"hi i'm adria\", \"user\": \"adriabama06\"}");
            //
            //Console.WriteLine(JObject.Parse(jsonPost.GetValue("json").ToString()).GetValue("conent"));

            //var ii = await Request.Post("/channels/872831681986437150/messages", "{ \"content\": \"hola desde c#\", \"tts\": false }");
            //
            //Console.WriteLine(ii.GetValue("id"));

            return 0;
        }
    }
}