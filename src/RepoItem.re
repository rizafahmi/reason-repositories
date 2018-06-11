let component = ReasonReact.statelessComponent("RepoItem");

let make = (~repositories: RepoData.repo, _children) => {
  ...component,
  render: _self => <div> (ReasonReact.string(repositories.name)) </div>,
};
