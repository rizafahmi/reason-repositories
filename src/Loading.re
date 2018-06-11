let component = ReasonReact.statelessComponent("Loading");

let make = _children => {
  ...component,
  render: _self =>
    <div className="bx--loading-overlay">
      <div className="bx--loading">
        <svg className="bx--loading__svg" viewBox="-75 -75 150 150">
          <title> (ReasonReact.string("Loading...")) </title>
          <circle cx="0" cy="0" r="37.5" />
        </svg>
      </div>
    </div>,
};
