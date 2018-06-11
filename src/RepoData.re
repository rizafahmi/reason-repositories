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
