[%bs.raw {|require('./App.css')|}];

type action =
  | Loaded(RepoData.repo);
type state = {repositories: option(RepoData.repo)};
let component = ReasonReact.reducerComponent("App");

let dummyRepo: RepoData.repo = {
  name: "facebook/reason",
  stargazers_count: 5841,
  url: "https://github.com/facebook/reason",
};

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
      | Some(repositories) => <RepoItem repositories />
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
