let component = ReasonReact.statelessComponent("RepoItem");

let make = (~repo: RepoData.repo, _children) => {
  ...component,
  render: _self =>
    <div className="bx--row">
      <div className="bx--col-xs-6">
        <a href=repo.url target="_blank"> (ReasonReact.string(repo.name)) </a>
      </div>
      <div className="bx--col-xs-6 stars">
        <span className="bx--tag bx--tag--ibm">
          (
            ReasonReact.string(
              string_of_int(repo.stargazers_count) ++ " stars",
            )
          )
        </span>
      </div>
    </div>,
};
