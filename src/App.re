[%bs.raw {|require('./App.css')|}];

type state = {repositories: option(RepoData.repo)};
let component = ReasonReact.reducerComponent("App");

let dummyRepo: RepoData.repo = {
  name: "facebook/reason",
  stargazers_count: 5841,
  url: "https://github.com/facebook/reason",
};

let make = (~title, _children) => {
  ...component,
  initialState: () => {repositories: Some(dummyRepo)},
  reducer: ((), _) => ReasonReact.NoUpdate,
  render: self => {
    let repoItem =
      switch (self.state.repositories) {
      | Some(repositories) => <RepoItem repositories />
      | None => <Loading />
      };
    <div className="container">
      <div className="page-header">
        <h1 className="page-header__title"> (ReasonReact.string(title)) </h1>
      </div>
      <div className="bx--grid content"> repoItem </div>
    </div>;
  },
};
