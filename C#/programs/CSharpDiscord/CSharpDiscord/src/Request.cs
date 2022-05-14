using System.Net.Http;
using System.Threading.Tasks;
using Newtonsoft.Json.Linq;
using System.Net;
using System.IO;
using System.Collections.Generic;
using Newtonsoft.Json;
using System.Text;
using System;

namespace CSharpDiscord.src
{
    class Request
    {
        public static string apiUrl = "https://discord.com/api/v8";
        private static string token;

        public static void setToken(string t) => token = t;

        public static async Task<JObject> Get(string url)
        {
            var httpClient = new HttpClient();
            httpClient.DefaultRequestHeaders.TryAddWithoutValidation("Content-Type", "application/json");
            httpClient.DefaultRequestHeaders.Add("Authorization", "Bot " + token);
            var res = await httpClient.GetAsync(apiUrl + url);
            string StrRes = await res.Content.ReadAsStringAsync();
            JObject toreturn = JObject.Parse(StrRes);

            return toreturn;
        }
        public static async Task<List<JObject>> ArrayGet(string url)
        {
            var httpClient = new HttpClient();
            httpClient.DefaultRequestHeaders.TryAddWithoutValidation("Content-Type", "application/json");
            httpClient.DefaultRequestHeaders.Add("Authorization", "Bot " + token);
            var res = await httpClient.GetAsync(apiUrl + url);
            string StrRes = await res.Content.ReadAsStringAsync();
            var jsonArray = JsonConvert.DeserializeObject<List<dynamic>>(StrRes);
            List<JObject> toreturn = new List<JObject>();

            for (int i = 0; i < jsonArray.Count; i++)
            {
                dynamic json = jsonArray[i];
                toreturn.Add(json);
            }

            return toreturn;
        }

        

        public static async Task<JObject> Post(string url, string data)
        {
            var strContent = new StringContent(data, Encoding.UTF8, "application/json");
            var httpClient = new HttpClient();
            httpClient.DefaultRequestHeaders.TryAddWithoutValidation("Content-Type", "application/json");
            httpClient.DefaultRequestHeaders.Add("Authorization", "Bot " + token);
            var res = await httpClient.PostAsync(apiUrl + url, strContent);
            string StrRes = await res.Content.ReadAsStringAsync();
            JObject toreturn = JObject.Parse(StrRes);

            return toreturn;
        }
        public static async Task<List<JObject>> ArrayPost(string url, string data)
        {
            var strContent = new StringContent(data, Encoding.UTF8, "application/json");
            var httpClient = new HttpClient();
            httpClient.DefaultRequestHeaders.TryAddWithoutValidation("Content-Type", "application/json");
            httpClient.DefaultRequestHeaders.Add("Authorization", "Bot " + token);
            var res = await httpClient.PostAsync(apiUrl + url, strContent);
            string StrRes = await res.Content.ReadAsStringAsync();
            var jsonArray = JsonConvert.DeserializeObject<List<dynamic>>(StrRes);
            List<JObject> toreturn = new List<JObject>();

            for (int i = 0; i < jsonArray.Count; i++)
            {
                dynamic json = jsonArray[i];
                toreturn.Add(json);
            }

            return toreturn;
        }
    }
}