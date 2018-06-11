[%bs.raw {|require('./App.css')|}];

type action =
  | Loaded(array(RepoData.repo));
type state = {repositories: option(array(RepoData.repo))};
let component = ReasonReact.reducerComponent("App");

let dummyRepo: array(RepoData.repo) = [|
  RepoData.parseRepoJson(
    Js.Json.parseExn(
      {js|
    {
      "full_name": "facebook/reason",
      "stargazers_count": 5841,
      "html_url": "https://github.com/facebook/reason"
    }
    |js},
    ),
  ),
|];

let make = (~title, _children) => {
  ...component,
  initialState: () => {repositories: None},
  didMount: self => {
    let handleFetchData = repositories => self.send(Loaded(repositories));
    RepoData.fetchRepos()
    |> Js.Promise.then_(repositories => {
         handleFetchData(repositories);
         Js.Promise.resolve();
       })
    |> ignore;
  },
  reducer: (action, _state) =>
    switch (action) {
    | Loaded(repositories) =>
      ReasonReact.Update({repositories: Some(repositories)})
    },
  render: self => {
    let repoItem =
      switch (self.state.repositories) {
      | Some(repositories) =>
        ReasonReact.arrayToElement(
          Array.map(
            (repo: RepoData.repo) => <RepoItem key=repo.name repo />,
            repositories,
          ),
        )
      | None => <Loading />
      };
    <div className="container">
      <div className="page-header">
        <h1 className="page-header__title"> (ReasonReact.string(title)) </h1>
      </div>
      <div className="bx--grid content"> repoItem </div>
      <footer className="page-footer">
        <div className="page-footer__content">
          <p className="page-footer__text">
            (ReasonReact.string("Copyright 2018 Riza Fahmi"))
          </p>
        </div>
      </footer>
    </div>;
  },
};
