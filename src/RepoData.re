type repo = {
  name: string,
  stargazers_count: int,
  url: string,
};

let parseRepoJson = (json: Js.Json.t) : repo => {
  name: Json.Decode.field("full_name", Json.Decode.string, json),
  stargazers_count:
    Json.Decode.field("stargazers_count", Json.Decode.int, json),
  url: Json.Decode.field("html_url", Json.Decode.string, json),
};

let parseResponseJson = json =>
  Json.Decode.field("items", Json.Decode.array(parseRepoJson), json);

let reposUrl = "https://api.github.com/search/repositories?q=topic%3Areasonml&type=Repositories";

let fetchRepos = () =>
  Bs_fetch.fetch(reposUrl)
  |> Js.Promise.then_(Bs_fetch.Response.text)
  |> Js.Promise.then_(jsonText =>
       Js.Promise.resolve(parseResponseJson(Js.Json.parseExn(jsonText)))
     );
