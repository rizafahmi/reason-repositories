[%bs.raw {|require('./App.css')|}];

type action =
  | Loaded(array(RepoData.repo));
type state = {repositories: option(array(RepoData.repo))};
let component = ReasonReact.reducerComponent("App");

let dummyRepo: array(RepoData.repo) = [|
  {
    name: "facebook/reason",
    stargazers_count: 5841,
    url: "https://github.com/facebook/reason",
  },
  {
    name: "jaredpalmer/razzle",
    stargazers_count: 4134,
    url: "https://github.com/jaredpalmer/razzle",
  },
|];

let make = (~title, _children) => {
  ...component,
  initialState: () => {repositories: None},
  reducer: (action, _state) =>
    switch (action) {
    | Loaded(repositories) =>
      ReasonReact.Update({repositories: Some(repositories)})
    },
  render: self => {
    let loadButton =
      <button onClick=(e => self.send(Loaded(dummyRepo)))>
        (ReasonReact.string("Load Repositories"))
      </button>;
    let repoItem =
      switch (self.state.repositories) {
      | Some(repositories) =>
        ReasonReact.arrayToElement(
          Array.map(
            (repositories: RepoData.repo) => <RepoItem repositories />,
            repositories,
          ),
        )
      | None => loadButton
      };
    <div className="container">
      <div className="page-header">
        <h1 className="page-header__title"> (ReasonReact.string(title)) </h1>
      </div>
      <div className="bx--grid content"> repoItem </div>
    </div>;
  },
};
