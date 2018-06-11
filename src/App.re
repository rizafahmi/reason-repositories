[%bs.raw {|require('./App.css')|}];

let component = ReasonReact.statelessComponent("App");

let make = (~title, _children) => {
  ...component,
  render: _self => {
    let dummyRepo: RepoData.repo = {
      name: "facebook/reason",
      stargazers_count: 5841,
      url: "https://github.com/facebook/reason",
    };
    <div className="container">
      <div className="page-header">
        <h1 className="page-header__title"> (ReasonReact.string(title)) </h1>
      </div>
      <div className="bx--grid content">
        <div className="bx--row">
          <div className="bx--col-xs-12">
            <RepoItem repositories=dummyRepo />
          </div>
        </div>
      </div>
    </div>;
  },
};
