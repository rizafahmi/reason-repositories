[%bs.raw {|require('./App.css')|}];

type state = {repositories: RepoData.repo};
let component = ReasonReact.reducerComponent("App");

let dummyRepo: RepoData.repo = {
  name: "facebook/reason",
  stargazers_count: 5841,
  url: "https://github.com/facebook/reason",
};

let make = (~title, _children) => {
  ...component,
  initialState: () => {repositories: dummyRepo},
  reducer: ((), _) => ReasonReact.NoUpdate,
  render: self =>
    <div className="container">
      <div className="page-header">
        <h1 className="page-header__title"> (ReasonReact.string(title)) </h1>
      </div>
      <div className="bx--grid content">
        <RepoItem repositories=self.state.repositories />
      </div>
    </div>,
};
