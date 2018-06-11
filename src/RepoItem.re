let component = ReasonReact.statelessComponent("RepoItem");

let make = (~repositories: RepoData.repo, _children) => {
  ...component,
  render: _self =>
    <div className="bx--row">
      <div className="bx--col-xs-6">
        <a href=repositories.url> (ReasonReact.string(repositories.name)) </a>
      </div>
      <div className="bx--col-xs-6 stars">
        <span className="bx--tag bx--tag--ibm">
          (
            ReasonReact.string(
              string_of_int(repositories.stargazers_count) ++ " stars",
            )
          )
        </span>
      </div>
    </div>,
};
