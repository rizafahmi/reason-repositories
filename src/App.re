[%bs.raw {|require('./App.css')|}];

let component = ReasonReact.statelessComponent("App");

let make = (~title, _children) => {
  ...component,
  render: _self =>
    <div className="container">
      <div className="page-header">
        <h1 className="page-header__title"> (ReasonReact.string(title)) </h1>
      </div>
      <div className="bx--grid content">
        <div className="bx--row">
          <div className="bx--col-xs-12">
            (ReasonReact.string("Content here.."))
          </div>
        </div>
      </div>
    </div>,
};
